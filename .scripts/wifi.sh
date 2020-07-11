#!/bin/bash

nmcli device wifi list

echo SSID:

read ssid

echo Password:

read password

clear

nmcli device wifi connect $ssid password $password
