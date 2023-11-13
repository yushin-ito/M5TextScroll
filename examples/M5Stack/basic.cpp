#include <M5Unified.h>
#include <M5TextScroll.h>

M5TextScroll ts;

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);

    ts.init(0, 0);
    ts.setText("Hello World!");
}

void loop() {
    M5.update();

    if (M5.BtnA.wasPressed()) {
        if (ts.isDrawing()) {
            ts.stop();
        }
        else {
            ts.start();
        }
    }

    if (M5.BtnB.wasPressed()) {
        ts.setText("BtnB was pressed!");
    }

    delay(100);
}