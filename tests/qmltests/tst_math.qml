import QtQuick 2.3
import QtTest 1.0

TestCase {
    name: "MathTests Test2"

    function test_math() {
        compare(2 + 2, 4, "2 + 2 = 4")
    }

    function test_fail() {
        compare(2 + 2, 5, "2 + 2 = 5")
    }
}

