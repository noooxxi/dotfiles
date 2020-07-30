#!/bin/sh

echo "External IP: $(curl ident.me -s | cut -d % -f1)"
echo "Internal IP: $(ip route get 1.2.3.4 | awk '{print $7}')"
