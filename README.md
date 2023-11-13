<h1>M5TextScroll</h1>

<div align="left">
  <img src="https://img.shields.io/badge/version-0.0.1-red.svg">
  <img src="https://img.shields.io/github/actions/workflow/status/yushin-ito/M5TextScroll/build.yml">
  <img src="https://img.shields.io/github/stars/yushin-ito/M5TextScroll?color=yellow">
  <img src="https://img.shields.io/github/commit-activity/t/yushin-ito/M5TextScroll">
  <img src="https://img.shields.io/badge/license-MIT-green">
</div>

<br>

<h2>📝 Overview</h2>
An M5Stack library for scrolling text.

<br>
<br>

<h2>🚀 Features</h2>
<ul>
  <li>Scroll from left to right on the lcd</li>
  <li>Customize color and speed</li>
</ul>
<br>
<div align="center">
  <img src="https://github.com/yushin-ito/M5TextScroll/assets/75526539/7a1514ee-3172-422f-889b-651a5821e1dd" width="80%"/>
</div>

<br>

<h2>📦 Installation</h2>
<a href="https://open.vscode.dev/yushin-ito/M5TextScroll">
  <img src="https://img.shields.io/static/v1?logo=visualstudiocode&label=&message=Open%20in%20Visual%20Studio%20Code&labelColor=2c2c32&color=007acc&logoColor=007acc">
</a>
<br>
<br>
<ol>
  <li>Initialize your Platform IO project</li>

```powershell
platformio init -d . -b m5stack-core-esp32
```

  <li>Install the library and its dependency</li>

```powershell
platformio lib install M5Clock
platformio lib install M5Unified
```

</ol>

<h2>🔧 Usage</h2>

> **Warning**
> This library has been tested only with M5Stack and M5StickC-PLUS.

<br>

```c++
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
```

<p>You can also read the <a href="https://github.com/yushin-ito/M5TextScroll/blob/main/doc/BASIC.md">module doc</a> for a list of supported calls.</p>

<br>

<h2>👀 Author</h2>
<a href="https://github.com/yushin-ito">Yushin Ito</a>

<br>
<br>

<h2>📜 License</h2>
<a href="https://github.com/yushin-ito/M5TextScroll/blob/main/LICENSE">MIT License</a>
