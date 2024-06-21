#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
  {0, 0},
  {1, 2},
  {2, 4},
  {3, 6},
  {4, 8}
};

#define train_count sizeof(train)/sizeof(train[0])

float rand_float()
{
  return (float) rand() / (float) RAND_MAX;
}

// x1, x2, x3, ..., b
// w1, w2, w3, ...
// y = x1*w1 + x2*w2 + x3*w3 + ... + b

float cost(float w, float b)
{
  float result = 0.0f;
  for (size_t i = 0; i < train_count; i++) {
    float x = train[i][0];
    float y = x*w + b;
    float d = y - train[i][1];
    result += d*d;
  }
  result /= train_count;
  return result;
}

float dcost(float w)
{
    float result = 0.0f;
    size_t n = train_count;
    for (int i = 0; i < train_count; i++) {
        float x = train[i][0];
        float y = train[i][1];
        result += 2*x*(x*w - y);
    }
    result /= n;
    return result;
}

// lim_{h -> 0} \frac{f(a+h) - f(a)}{h}
// finite differences, approximation of dcost

// backpropagation
// newton method applied to the function f(x) = 2x => g(x) = 0

// cut the no of epoch by a factor of 1

int main()
{
  srand(time(0));
  float w = rand_float()*10.0f;
  float b = rand_float()*5.0f;
    
  // float eps = 1e-3;
  float rate = 1e-3;

  printf("%f\n", dcost(w));
  for (size_t i = 0; i < 50; i++) {
    float dw = dcost(w); // (cost(w + eps, b) - c)/eps;
    float db = dcost(b); // (cost(w, b + eps) - c)/eps;
    w -= rate*dw;
    b -= rate*db;
    printf("cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
  }

  printf("--------------------------------------\n");
  printf("w = %f, b = %f\n", w, b);

  return 0;
}

