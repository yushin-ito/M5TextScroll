#include <M5Unified.h>
#include <M5TextScroll.h>

M5TextScroll ts;

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);
    ts.setCusor(0, M5.Display.height() / 2, 1);
    ts.setText("Hello World!");
}

void loop() {
    ts.showTextScroll();
}