#
# SConscript for common-v4.5
# Created: Aug 16, 2006 - Jdw
# Updated: Aug 23, 2006 - Jdw
#          Add object install
#          Mar 30, 2011 jdw clone environment
Import('env')
env=env.Clone()
#
if (len(env.subst('$MYDEBUG')) > 0):
	dict = env.Dictionary()
	for k,v in dict.items():
		print  k, " = ", str(v)
#
libName = 'common'
libSrcList =['src/RcsbPlatform.C',
	     'src/RcsbFile.C',
	     'src/BlockIO.C',
	     'src/CifString.C',
	     'src/Serializer.C',
	     'src/GenString.C',
	     'src/GenCont.C',
	     'src/Exceptions.C',
	     'src/DataInfo.C',
     	     'src/mapped_vector.C',
       	     'src/mapped_ptr_vector.C']
libObjList = [s.replace('.C','.o') for s in libSrcList]
#
libIncList =['include/RcsbPlatform.h',
	     'include/RcsbFile.h',
	     'include/BlockIO.h',
	     'include/CifString.h',
	     'include/Serializer.h',
	     'include/rcsb_types.h',
	     'include/GenString.h',
	     'include/GenCont.h',
	     'include/Exceptions.h',
	     'include/DataInfo.h',
     	     'include/mapped_vector.h',
       	     'include/mapped_ptr_vector.h',
     	     'src/mapped_vector.C',
       	     'src/mapped_ptr_vector.C']
#
myLib=env.Library(libName,libSrcList)
#
#
env.Install(env.subst('$MY_LIB_INSTALL_PATH'),myLib)
env.Alias('install-lib',env.subst('$MY_LIB_INSTALL_PATH'))
#
env.Install(env.subst('$MY_INCLUDE_INSTALL_PATH'),libIncList)
env.Alias('install-include',env.subst('$MY_INCLUDE_INSTALL_PATH'))
#
env.Default('install-lib','install-include')
#
env.Install(env.subst('$MY_OBJ_INSTALL_PATH'),libObjList)
env.Alias('install-obj',env.subst('$MY_OBJ_INSTALL_PATH'))
#
env.Default('install-lib','install-include','install-obj')
#
