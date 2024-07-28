int add() {

	return 1;
}
int main() {
	int (*func1)(void  *) = &add;
	return 0;
}
