#!/bin/perl
use File::Basename;
$dir = `pwd`;
$base = basename($dir);
chomp($base);
open(INF,$ARGV[0]);
chomp($version = <INF>);
$base =~ m/-v/g;
$i1= pos $base;
$base =~ m/-/g;
$i2= pos $base;
$base2=substr($base,0,$i1).$version.substr($base,$i2-1).'-src';
$old_dir=$ARGV[1];
system("mv $old_dir $base2");
system("tar -cf - $base2 | gzip -cf - > $base2'.tar.gz'");
system("rm -rf $base2");

exit(0);
