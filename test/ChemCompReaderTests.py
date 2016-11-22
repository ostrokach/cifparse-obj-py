##
#
# File:    ChemCompReaderTests.py
# Author:  J. Westbrook
# Date:    13-Jan-2012
# Version: 0.001
##
"""
Test cases for reading and updating chemical component dictionary using Python CorePyWrap
wrapper module to C++ CifFile class library of file and dictionary tools.

"""
__docformat__ = "restructuredtext en"
__author__    = "John Westbrook"
__email__     = "jwest@rcsb.rutgers.edu"
__license__   = "Creative Commons Attribution 3.0 Unported"
__version__   = "V0.01"

import sys, unittest, traceback, filecmp
import sys, time, os, os.path, shutil

from CorePyWrap import ParseCif

class ChemCompReaderTests(unittest.TestCase):
    
    def setUp(self):
        self.__lfh=sys.stdout
        self.__verbose=True
        self.__pathPdbxDataFile       = "../data/1kip.cif"
        self.__pathBigPdbxDataFile    = "../data/2j01.cif"
        self.__pathChemCompDictFile   = "/data/components/cc-dict/Components-all-v3.cif"
        self.__pathPdbxDictFile       = "../data/mmcif_pdbx_v40.dic"
        self.__pathOutputPdbxFile     = "myPdbxOutputFile.cif"
        self.__pathBigOutputPdbxFile  = "myBigPdbxOutputFile.cif"        

    def tearDown(self):
        pass


    def testChemCompIndexDictionary(self): 
        """Test case -  read chemical dictionary and create index
        """
        self.__lfh.write("\nStarting %s %s\n" % (self.__class__.__name__,
                                               sys._getframe().f_code.co_name))
        try:
            myReader=ParseCif(self.__pathChemCompDictFile)
            #self.__lfh.write("Persistent index dictionary %r\n" % indexD.items())
        except:
            traceback.print_exc(file=self.__lfh)
            self.fail()

def suite():
    return unittest.makeSuite(ChemCompReaderTests,'test')


def suiteChemComp():
    suiteSelect = unittest.TestSuite()
    suiteSelect.addTest(ChemCompReaderTests("testChemCompIndexDictionary"))
    return suiteSelect

if __name__ == '__main__':
    # Run all tests -- 
    # unittest.main()
    #
    mySuite=suiteChemComp()
    unittest.TextTestRunner(verbosity=2).run(mySuite)


