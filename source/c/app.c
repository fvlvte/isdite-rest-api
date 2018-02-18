#include <isdite/foundation/app.h>
#include <isdite/foundation/log.h>
#include <stdio.h>

isResult AppMain(int argc, char ** argv)
{
  isdite_fn_syslog(1, "IRA Startup!");

  
  return isSuccess;
}

ISDITE_APP(AppMain);
