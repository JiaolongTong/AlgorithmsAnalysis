#!/bin/bash
mkimage -T omapimage -a 0x402F0400 -d $1 MLO
