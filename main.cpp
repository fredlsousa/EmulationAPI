#include <iostream>
#include "Tests/func_Tests.h"
#include "Tests/unit_System.h"
#include "Tests/unit_Flow.h"
#include "Tests/unit_Model.h"

int main() {
    exponentialTest();
    logisticTest();
    finalTest();
    unitarySystemTest();
    unitaryFlowTest();
    unitaryModelTest();
    return 0;
}
