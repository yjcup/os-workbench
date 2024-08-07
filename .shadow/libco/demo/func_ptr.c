int add() { return 1; }
int main() {
  int (*func1)(void) = &add;
  func1();
  return 0;
}
