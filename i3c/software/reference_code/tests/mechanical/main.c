extern void runAllMechanicalTests();

__attribute__((weak))
int main(void) {
    runAllMechanicalTests();
    return 0;
}
