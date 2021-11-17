/*************************************************************************************
Copyright 2020 Xilinx Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
  http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/


static float hls_LUT_EXP[256] = {
1.266417e-14 , 1.626111e-14 , 2.087968e-14 , 2.681004e-14 , 3.442477e-14 , 4.420228e-14 , 5.675685e-14 , 7.287724e-14 , 9.357623e-14 , 1.201543e-13 , 1.542811e-13 , 1.981009e-13 , 2.543666e-13 , 3.266131e-13 , 4.193796e-13 , 5.384940e-13 , 6.914400e-13 , 8.878265e-13 , 1.139992e-12 , 1.463779e-12 , 1.879529e-12 , 2.413363e-12 , 3.098819e-12 , 3.978963e-12 , 5.109089e-12 , 6.560200e-12 , 8.423463e-12 , 1.081594e-11 , 1.388794e-11 , 1.783247e-11 , 2.289735e-11 , 2.940078e-11 , 3.775134e-11 , 4.847369e-11 , 6.224145e-11 , 7.991960e-11 , 1.026188e-10 , 1.317651e-10 , 1.691898e-10 , 2.172440e-10 , 2.789468e-10 , 3.581748e-10 , 4.599055e-10 , 5.905304e-10 , 7.582560e-10 , 9.736201e-10 , 1.250153e-09 , 1.605228e-09 , 2.061154e-09 , 2.646574e-09 , 3.398268e-09 , 4.363462e-09 , 5.602796e-09 , 7.194133e-09 , 9.237450e-09 , 1.186112e-08 , 1.522998e-08 , 1.955568e-08 , 2.510999e-08 , 3.224187e-08 , 4.139938e-08 , 5.315785e-08 , 6.825604e-08 , 8.764248e-08 , 1.125352e-07 , 1.444980e-07 , 1.855391e-07 , 2.382370e-07 , 3.059023e-07 , 3.927863e-07 , 5.043477e-07 , 6.475952e-07 , 8.315287e-07 , 1.067704e-06 , 1.370959e-06 , 1.760346e-06 , 2.260329e-06 , 2.902320e-06 , 3.726653e-06 , 4.785117e-06 , 6.144212e-06 , 7.889324e-06 , 1.013009e-05 , 1.300730e-05 , 1.670170e-05 , 2.144541e-05 , 2.753645e-05 , 3.535750e-05 , 4.539993e-05 , 5.829466e-05 , 7.485183e-05 , 9.611165e-05 , 1.234098e-04 , 1.584613e-04 , 2.034684e-04 , 2.612586e-04 , 3.354626e-04 , 4.307425e-04 , 5.530844e-04 , 7.101744e-04 , 9.118820e-04 , 1.170880e-03 , 1.503439e-03 , 1.930454e-03 , 2.478752e-03 , 3.182781e-03 , 4.086772e-03 , 5.247518e-03 , 6.737947e-03 , 8.651695e-03 , 1.110900e-02 , 1.426423e-02 , 1.831564e-02 , 2.351775e-02 , 3.019738e-02 , 3.877421e-02 , 4.978707e-02 , 6.392786e-02 , 8.208500e-02 , 1.053992e-01 , 1.353353e-01 , 1.737739e-01 , 2.231302e-01 , 2.865048e-01 , 3.678795e-01 , 4.723665e-01 , 6.065307e-01 , 7.788008e-01 , 1.000000e+00 , 1.284025e+00 , 1.648721e+00 , 2.117000e+00 , 2.718282e+00 , 3.490343e+00 , 4.481689e+00 , 5.754602e+00 , 7.389056e+00 , 9.487736e+00 , 1.218249e+01 , 1.564263e+01 , 2.008554e+01 , 2.579034e+01 , 3.311545e+01 , 4.252108e+01 , 5.459815e+01 , 7.010542e+01 , 9.001714e+01 , 1.155843e+02 , 1.484132e+02 , 1.905663e+02 , 2.446919e+02 , 3.141907e+02 , 4.034288e+02 , 5.180128e+02 , 6.651416e+02 , 8.540588e+02 , 1.096633e+03 , 1.408105e+03 , 1.808042e+03 , 2.321573e+03 , 2.980958e+03 , 3.827626e+03 , 4.914769e+03 , 6.310688e+03 , 8.103084e+03 , 1.040457e+04 , 1.335973e+04 , 1.715423e+04 , 2.202646e+04 , 2.828254e+04 , 3.631550e+04 , 4.663003e+04 , 5.987414e+04 , 7.687992e+04 , 9.871577e+04 , 1.267536e+05 , 1.627548e+05 , 2.089813e+05 , 2.683373e+05 , 3.445519e+05 , 4.424134e+05 , 5.680701e+05 , 7.294164e+05 , 9.365891e+05 , 1.202604e+06 , 1.544174e+06 , 1.982759e+06 , 2.545913e+06 , 3.269018e+06 , 4.197502e+06 , 5.389698e+06 , 6.920510e+06 , 8.886111e+06 , 1.140999e+07 , 1.465072e+07 , 1.881190e+07 , 2.415495e+07 , 3.101557e+07 , 3.982478e+07 , 5.113604e+07 , 6.565997e+07 , 8.430907e+07 , 1.082550e+08 , 1.390022e+08 , 1.784823e+08 , 2.291758e+08 , 2.942676e+08 , 3.778470e+08 , 4.851652e+08 , 6.229644e+08 , 7.999022e+08 , 1.027095e+09 , 1.318816e+09 , 1.693393e+09 , 2.174360e+09 , 2.791933e+09 , 3.584913e+09 , 4.603119e+09 , 5.910522e+09 , 7.589260e+09 , 9.744804e+09 , 1.251258e+10 , 1.606646e+10 , 2.062975e+10 , 2.648912e+10 , 3.401271e+10 , 4.367318e+10 , 5.607747e+10 , 7.200490e+10 , 9.245612e+10 , 1.187160e+11 , 1.524344e+11 , 1.957296e+11 , 2.513218e+11 , 3.227036e+11 , 4.143596e+11 , 5.320482e+11 , 6.831635e+11 , 8.771992e+11 , 1.126346e+12 , 1.446257e+12 , 1.857031e+12 , 2.384475e+12 , 3.061726e+12 , 3.931334e+12 , 5.047933e+12 , 6.481675e+12 , 8.322635e+12 , 1.068647e+13 , 1.372171e+13 , 1.761902e+13 , 2.262327e+13 , 2.904885e+13 , 3.729946e+13 , 4.789346e+13 , 6.149642e+13 };
