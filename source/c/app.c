#include <isdite/foundation/app.h>
#include <stdio.h>

isResult AppMain(int argc, char ** argv)
{
  printf("test");
  return isSuccess;
}

ISDITE_APP(AppMain);
