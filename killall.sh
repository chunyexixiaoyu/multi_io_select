#!/bin/bash
mainthread="server"
taskthread="client"
kill -9 $(pidof $taskthread)
kill -9 $(pidof $mainthread)






