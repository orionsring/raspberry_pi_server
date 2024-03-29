upstream node{
    server 127.0.0.1:8080;
}
server{
    listen 80;
    ssl off;
    ssl_certificate /etc/nginx/public.crt;
    ssl_certificate_key /etc/nginx/private.rsa;
    root /usr/share/nginx/aym;
    try_files $uri @node;
        location @node{
            proxy_set_header         X-Real-IP          $remote_addr;
		        proxy_set_heaeder    X-Forwarded-For    $proxy_add_x_forwarded_for;
                proxy_set_header     Host               $http_host;
			    proxy_redirect       off;
			proxy_pass               http://node;
			}
		}
	}
	
	
	
	