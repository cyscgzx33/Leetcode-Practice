#include <stdio.h>
#include <unistd.h>

class Foo {
public:
  Foo() {};
  ~Foo() { printf("Yay!\n"); }
} bar;

int main(int argc, char **argv) {
  sleep(5);
}