#include <isdite/foundation/app.h>
#include <isdite/foundation/log.h>
#include <isdite/foundation/tcp_server.h>
#include <stdio.h>
#include <unistd.h>

isResult AppMain(int argc, char ** argv)
{
  isdite_fdn_fsyslog(IL_INFO, "IRA Startup!");

  isdite_fn_tcpServer_create("0.0.0.0", 8080, 100000);

  while(1==1)
  {
    usleep(1000);
  }

  return isSuccess;
}

ISDITE_APP(AppMain);
