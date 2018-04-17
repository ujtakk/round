#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np

A = np.loadtxt("input.dat").astype("float32")

B = np.around(A * 16777216.0)
B = np.stack((B, np.around(A / 256.0)), axis=-1)

np.savetxt("result_py.dat", B.ravel(), fmt="%d")
