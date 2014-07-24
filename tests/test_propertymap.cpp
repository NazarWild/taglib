#include <cppunit/extensions/HelperMacros.h>
#include <tpropertymap.h>
class TestPropertyMap : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(TestPropertyMap);
  CPPUNIT_TEST(testInvalidKeys);
  CPPUNIT_TEST_SUITE_END();

public:
  void testInvalidKeys()
  {
    TagLib::PropertyMap map1;
    CPPUNIT_ASSERT(map1.isEmpty());
    map1[L"\x00c4\x00d6\x00dc"].append("test");
    CPPUNIT_ASSERT_EQUAL(map1.size(), (size_t)1);

    TagLib::PropertyMap map2;
    map2[L"\x00c4\x00d6\x00dc"].append("test");
    CPPUNIT_ASSERT(map1 == map2);
    CPPUNIT_ASSERT(map1.contains(map2));

    map2["ARTIST"] = TagLib::String("Test Artist");
    CPPUNIT_ASSERT(map1 != map2);
    CPPUNIT_ASSERT(map2.contains(map1));

    map2["\xc4\xd6\xdc"].append("test 2");
    map2[L"\x00c4\x00d6\x00dc"].append("test 2");
    CPPUNIT_ASSERT(!map2.contains(map1));

  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestPropertyMap);
