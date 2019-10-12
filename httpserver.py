import http.server
import sys

Handler = http.server.CGIHTTPRequest Handler
Port = 8002
httpd = http.server.HTTPServer(("",PORT),Handler)

