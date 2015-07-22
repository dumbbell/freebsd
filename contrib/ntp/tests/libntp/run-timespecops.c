/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_Helpers1();
extern void test_Normalise();
extern void test_SignNoFrac();
extern void test_SignWithFrac();
extern void test_CmpFracEQ();
extern void test_CmpFracGT();
extern void test_CmpFracLT();
extern void test_AddFullNorm();
extern void test_AddFullOflow1();
extern void test_AddNsecNorm();
extern void test_AddNsecOflow1();
extern void test_SubFullNorm();
extern void test_SubFullOflow();
extern void test_SubNsecNorm();
extern void test_SubNsecOflow();
extern void test_Neg();
extern void test_AbsNoFrac();
extern void test_AbsWithFrac();
extern void test_Helpers2();
extern void test_ToLFPbittest();
extern void test_ToLFPrelPos();
extern void test_ToLFPrelNeg();
extern void test_ToLFPabs();
extern void test_FromLFPbittest();
extern void test_FromLFPrelPos();
extern void test_FromLFPrelNeg();
extern void test_LFProundtrip();
extern void test_ToString();


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}

char *progname;


//=======MAIN=====
int main(int argc, char *argv[])
{
  progname = argv[0];
  Unity.TestFile = "timespecops.c";
  UnityBegin("timespecops.c");
  RUN_TEST(test_Helpers1, 155);
  RUN_TEST(test_Normalise, 175);
  RUN_TEST(test_SignNoFrac, 189);
  RUN_TEST(test_SignWithFrac, 201);
  RUN_TEST(test_CmpFracEQ, 215);
  RUN_TEST(test_CmpFracGT, 228);
  RUN_TEST(test_CmpFracLT, 241);
  RUN_TEST(test_AddFullNorm, 258);
  RUN_TEST(test_AddFullOflow1, 272);
  RUN_TEST(test_AddNsecNorm, 286);
  RUN_TEST(test_AddNsecOflow1, 298);
  RUN_TEST(test_SubFullNorm, 314);
  RUN_TEST(test_SubFullOflow, 328);
  RUN_TEST(test_SubNsecNorm, 342);
  RUN_TEST(test_SubNsecOflow, 354);
  RUN_TEST(test_Neg, 370);
  RUN_TEST(test_AbsNoFrac, 387);
  RUN_TEST(test_AbsWithFrac, 398);
  RUN_TEST(test_Helpers2, 413);
  RUN_TEST(test_ToLFPbittest, 445);
  RUN_TEST(test_ToLFPrelPos, 458);
  RUN_TEST(test_ToLFPrelNeg, 470);
  RUN_TEST(test_ToLFPabs, 482);
  RUN_TEST(test_FromLFPbittest, 497);
  RUN_TEST(test_FromLFPrelPos, 516);
  RUN_TEST(test_FromLFPrelNeg, 529);
  RUN_TEST(test_LFProundtrip, 544);
  RUN_TEST(test_ToString, 563);

  return (UnityEnd());
}
