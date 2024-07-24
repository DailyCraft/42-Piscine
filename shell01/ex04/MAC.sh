#!/bin/sh
ifconfig | grep -oE '.{2}:.{2}:.{2}:.{2}:.{2}:.{2}'
