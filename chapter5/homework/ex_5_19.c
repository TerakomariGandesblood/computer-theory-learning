//
// Created by kaiser on 18-12-5.
//

void psum1a(float a[], float p[], long n) {
  long i;
  float last_val, val;
  last_val = p[0] = a[0];
  for (i = 1; i < n; i++) {
    val = last_val + a[i];
    p[i] = val;
    last_val = val;
  }
}

void psum4_1a(float a[], float p[], long n) {
  long i;
  float last_val;
  float temp, temp1, temp2, temp3;
  last_val = p[0] = a[0];
  for (i = 1; i < n - 3; i += 4) {
    temp = last_val + a[i];
    temp1 = temp + a[i + 1];
    temp2 = temp1 + a[i + 2];
    temp3 = temp2 + a[i + 3];

    p[i] = temp;
    p[i + 1] = temp1;
    p[i + 2] = temp2;
    p[i + 3] = temp3;

    last_val = temp3;
  }

  for (; i < n; i++) {
    last_val += a[i];
    p[i] = last_val;
  }
}
