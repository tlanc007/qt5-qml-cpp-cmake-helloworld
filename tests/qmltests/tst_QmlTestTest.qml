import QtQuick 2.3
import QtTest 1.0

TestCase {
    name: "QmlTest Test"

    function test_add() {
        compare(2 + 2, 4, "2 + 2 = 4")
    }

    function test_fail() {
        compare(2 + 2, 5, "2 + 2 = 5")
    }
}

