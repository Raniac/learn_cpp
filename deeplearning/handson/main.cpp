#include <iostream>
#include <vector>
#include "DataObject.h"
#include "Utilities.h"

static void testDataObject() {
    DLHandsOn::DataObject();
    return;
}

int main() {
    testDataObject();
    DLHandsOn::assert(false, "lalalala");
    return 0;
}