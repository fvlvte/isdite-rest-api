#include <isdite/foundation/app.h>
#include <isdite/foundation/log.h>
#include <isdite/foundation/https_server.h>
#include <string.h>

void App_onGetHello
(
  is_tcpServer server,
  is_tcpClient client,
  is_string data,
  int size,
  void (*callback)(const void *, const void*, const void*, int, int),
  is_httpsServer instance
)
{
  const char * msg = "{\"message\":\"hello world\"}";
  callback(server, client, msg, strlen(msg), 1);
}

isResult AppMain(int argc, char ** argv)
{
  isdite_fdn_fsyslog(IL_INFO, "IRA Startup!");

  is_httpsServer s =
    isdite_net_httpsServer_create
    (
      "0.0.0.0",
      443,
      "cert.der",
      "priv.der"
    );

  is_httpsVhost vh = isdite_net_httpsServer_addVirtualHost(s, "127.0.0.1:8080");
  is_httpsVhost vh2 = isdite_net_httpsServer_addVirtualHost(s, "api.isdite.com");
  isdite_net_httpsServer_bindEndpoint(vh, "/hello", "GET", &App_onGetHello);
  isdite_net_httpsServer_bindEndpoint(vh2, "/hello", "GET", &App_onGetHello);

  isdite_net_httpsServer_join(s);

  return isSuccess;
}

ISDITE_APP(AppMain);
