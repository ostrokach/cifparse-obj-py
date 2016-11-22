#!/bin/perl
if ($#ARGV < 2) {
    print "usage: fileUpdate patternlistfile file[file] dir \n";
    exit(1);
}
use File::Copy;
use File::Basename;
use Time::Local;
$listfile = $ARGV[0];
$dir = $ARGV[$#ARGV];
$tmp_in_file = 'tmp.in';
$tmp_out_file = 'tmp.out';

for ($i=1; $i<$#ARGV;$i++) {
  $infile =  $ARGV[$i];
  $filename =  basename($infile);
  @comment = get_comment_sign($filename);
  $outfile = $dir."/".$filename;
  open(INF,$infile);
  open(LISTF, $listfile);
  open(OUTF, ">$tmp_out_file");

# read in each line of the file
  while ($listline = <LISTF>) {
    @array = split(" ",$listline);
	 $array[0]=~ s/\$/\\\$/g;
    while ($line = <INF>) {
      if($line =~ $array[0]) {
		  if    ($line =~ /FILE/)    {  put_filename($filename);}
		  elsif ($line =~ /VERSION/)   { put_version($array[1]);}
		  elsif ($line =~ /DATE/)    { put_date(); put_contact();put_copyright();}
		  else
			 {
				open(PTNF, $array[1]);
				if ($#comment==0) {
				  while ($line2 = <PTNF>) {
					 print OUTF @comment[0],$line2;
				  }
				}
				else {
				  print OUTF @comment[0],"\n";
				  while ($line2 = <PTNF>) {
					 print OUTF $line2;
				  }
				  print OUTF @comment[1],"\n";
				  close(PTNF);
				}
			 }
		}
		else {
		  print OUTF $line;
		}
	 }
	 close(INF);
	 close(OUTF);
	 copy($tmp_out_file,$tmp_in_file);
	 open(INF, $tmp_in_file);
	 open(OUTF,"> $tmp_out_file");
	 
  }
  close(INF);
  close(LISTF);
  close(OUTF);
  copy($tmp_in_file,$outfile);
  system("rm $tmp_in_file");
  system("rm $tmp_out_file");
}
exit(0);

sub get_comment_sign
{
  my $ext;
  my @commentsign;
  my $i;
  my $filename = $_[0];
  my $ext;
  $i = index($filename,".");
  $ext = substr($filename,$i);
  if ($i!=-1) {
# two comment sign if first goes to beginig of comment, the other goes at the
# end. one sign - goest to begining of each line of comment
  for ($ext) {
    if    (/\.c$/)    { @commentsign =  ("/*","*/"); }
    elsif (/\.cc$/)   { @commentsign =  ("/*","*/");}
    elsif (/\.C$/)    { @commentsign =  ("/*","*/");}
    elsif (/\.CC$/)   { @commentsign =  ("/*","*/");}
    elsif (/\.cpp$/)  { @commentsign = ("/*","*/"); }
    elsif (/\.CPP$/)  { @commentsign = ("/*","*/"); }
    elsif (/\.cxx$/)  { @commentsign = ("/*","*/"); }
    elsif (/\.CXX$/)  { @commentsign = ("/*","*/"); }
    elsif (/\.h$/)    { @commentsign = ("/*","*/"); }
    elsif (/\.hxx$/)  { @commentsign = ("/*","*/"); }
    elsif (/\.y$/)    { @commentsign = ("/*","*/"); }
    elsif (/\.l$/)    { @commentsign = ("/*","*/"); }
    elsif (/\.f$/)    { @commentsign = "C    "; }
    elsif (/\.pl$/)   { @commentsign = "#"; }
    elsif (/\.py$/)   { @commentsign = "#"; }
    elsif (/\.sh$/)   { @commentsign = "#"; } 
    elsif (/\.csh$/)  { @commentsign = "#"; } 
  }
}
#  print @commentsign[0],"\n";  #firstelement in @commentsign
#  print $#commentsign,"\n";  #number of elements in array @commentsign
  return @commentsign;
}

sub put_filename
{
  my $filename=$_[0];
  if ($#comment==0) {
	 print OUTF @comment[0],"  FILE:        ",$filename,"\n";
  }
  else {
	 print OUTF @comment[0],"\n";
	 print OUTF "FILE:     ",$filename,"\n";
	 print OUTF @comment[1],"\n";
  }
}

sub put_date
  {
  my $date;
  my $month;
  my $year;
#  my $tm = localtime;
($seconds, $minutes, $hours, $dayofmonth, $month, $year,
$weekday, $dayofyear, $dst) = localtime(time);
#  ($day,$month,$year) = (tm->mday,tm->mon, tm->year);
  if ($#comment==0) {
	 print OUTF @comment[0],"  DATE:        ",month+1,"/",$dayofmonth,"/",$year+1900,"\n";
  }
  else {
	 print OUTF @comment[0],"\n";
	 print OUTF "DATE:     ",$month+1,"/",$dayofmonth,"/",$year+1900,"\n";
	 print OUTF @comment[1],"\n";
  }
}

sub put_version
  {
	 open(PTNF, $_[0]);
	 if ($#comment==0) {
		while ($line2 = <PTNF>) {
		  print OUTF @comment[0],"  VERSION:     ",$line2;
		}
	 }
	 else {
		print OUTF @comment[0],"\n";
		while ($line2 = <PTNF>) {
		  print OUTF "VERSION:  ",$line2;
		}
		print OUTF @comment[1],"\n";
		close(PTNF);
	 }
  }

sub put_contact
  {
	 if ($#comment==0) {
		  print OUTF @comment[0],"  Comments and Questions to: sw-help\@rcsb.rutgers.edu","\n";
	 }
	 else {
		print OUTF @comment[0],"\n";
		print OUTF "  Comments and Questions to: sw-help\@rcsb.rutgers.edu","\n";
		print OUTF @comment[1],"\n";
		close(PTNF);
	 }
  }

sub put_copyright
  {
  my $date;
  my $month;
  my $year;
($seconds, $minutes, $hours, $dayofmonth, $month, $year,
$weekday, $dayofyear, $dst) = localtime(time);
	 if ($#comment==0) {
		print OUTF @comment[0],"COPYRIGHT 1999-",$year+1900, " Rutgers - The State University of New Jersey","\n";
		print OUTF @comment[0],"\n";
		print OUTF @comment[0],"This software is provided WITHOUT WARRANTY OF MERCHANTABILITY OR","\n";
		print OUTF @comment[0],"FITNESS FOR A PARTICULAR PURPOSE OR ANY OTHER WARRANTY, EXPRESS OR","\n";
		print OUTF @comment[0],"IMPLIED.  RUTGERS MAKE NO REPRESENTATION OR WARRANTY THAT THE","\n";
		print OUTF @comment[0],"SOFTWARE WILL NOT INFRINGE ANY PATENT, COPYRIGHT OR OTHER","\n";
		print OUTF @comment[0],"PROPRIETARY RIGHT.","\n";
		print OUTF @comment[0],"\n";
		print OUTF @comment[0],"The user of this software shall indemnify, hold harmless and defend","\n";
		print OUTF @comment[0],"Rutgers, its governors, trustees, officers, employees, students,","\n";
		print OUTF @comment[0],"agents and the authors against any and all claims, suits,","\n";
		print OUTF @comment[0],"losses, liabilities, damages, costs, fees, and expenses including","\n";
		print OUTF @comment[0],"reasonable attorneys' fees resulting from or arising out of the","\n";
		print OUTF @comment[0],"use of this software.  This indemnification shall include, but is","\n";
		print OUTF @comment[0],"not limited to, any and all claims alleging products liability.","\n";
	 }
	 else {
		print OUTF @comment[0],"\n";
		print OUTF "COPYRIGHT 1999-",$year+1900, " Rutgers - The State University of New Jersey","\n";
		print OUTF "\n";
		print OUTF "This software is provided WITHOUT WARRANTY OF MERCHANTABILITY OR","\n";
		print OUTF "FITNESS FOR A PARTICULAR PURPOSE OR ANY OTHER WARRANTY, EXPRESS OR","\n";
		print OUTF "IMPLIED.  RUTGERS MAKE NO REPRESENTATION OR WARRANTY THAT THE","\n";
		print OUTF "SOFTWARE WILL NOT INFRINGE ANY PATENT, COPYRIGHT OR OTHER","\n";
		print OUTF "PROPRIETARY RIGHT.","\n";
		print OUTF "\n";
		print OUTF "The user of this software shall indemnify, hold harmless and defend","\n";
		print OUTF "Rutgers, its governors, trustees, officers, employees, students,","\n";
		print OUTF "agents and the authors against any and all claims, suits,","\n";
		print OUTF "losses, liabilities, damages, costs, fees, and expenses including","\n";
		print OUTF "reasonable attorneys' fees resulting from or arising out of the","\n";
		print OUTF "use of this software.  This indemnification shall include, but is","\n";
		print OUTF "not limited to, any and all claims alleging products liability.","\n";

		print OUTF @comment[1],"\n";
		close(PTNF);
	 }
}
