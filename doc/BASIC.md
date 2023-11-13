# Basics

- [Basics](#basics)
  - [Instance Basics](#instance-basics)
    - [Create a instance](#create-a-instance)
  - [Functions Basic](#functions-basic)
    - [ts.setPosition(x, y) => void](#tssetPositionx-y--void)
    - [ts.setSpeed(speed) => void](#tssetspeedspeed--void)
    - [ts.setTextFont(font) => void](#tssettextfontfont--void)
    - [ts.setBgColor(color) => void](#tssetbgcolorcolor--void)
    - [ts.setTextColor(color) => void](#tssettextcolorcolor--void)
    - [ts.setText(text) => void](#tssettexttext--void)
    - [ts.init(x, y) => void](#tsinitx-y--void)
    - [ts.start() => void](#tsstart--void)
    - [ts.stop() => void](#tsstop--void)
    - [ts.isDrawing() => bool](#tsisdrawing--bool)
    - [ts.isChanged() => bool](#tsischanged--bool)
    - [ts.drawTextScroll() => void](#tsdrawtextscroll--void)
    - [ts.getScrollCount() => uint8_t](#tsgetscrollcount--uint8_t)

## Instance Basics

### Create a instance

Include the `M5TextScroll.h` and `M5Unified`

```c++
#include <M5Unified.h>
#include <M5TextScroll.h>
```

Then Instanciate

```c++
M5TextScroll ts;
```

Your instance is now ready.

## Functions Basic

Call the fuctions using the created instance.

### ts.setPosition(x, y) => void

Set position of text scroll box.

Kind: instance method of `M5TextScroll`

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

### ts.setSpeed(speed) => void

Set scroll pixel.

Kind: instance method of `M5TextScroll`

| Param |  Type   |
| :---: | :-----: |
| speed | uint8_t |

### ts.setTextFont(font) => void

Set font of text.

Kind: instance method of `M5TextScroll`

| Param |     Type      |
| :---: | :-----------: |
| font  | lgfx::IFont\* |

### ts.setBgColor(color) => void

Set bg color of text scroll box.

Kind: instance method of `M5TextScroll`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### ts.setTextColor(color) => void

Set bg color of text.

Kind: instance method of `M5TextScroll`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### ts.setText(text) => void

Set scrolling text.

Kind: instance method of `M5TextScroll`

| Param |     Type     |
| :---: | :----------: |
| text  | const chat\* |

### ts.init(x, y) => void

Initialize text scroll with position.

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

Kind: instance method of `M5TextSCroll`

### ts.start() => void

Start text scroll.

Kind: instance method of `M5TextSCroll`

### ts.stop() => void

Stop text scroll.

Kind: instance method of `M5TextSCroll`

### ts.isDrawing() => bool

Get if the text scroll is drawing.

Kind: instance method of `M5TextSCroll`

### ts.isChanged() => bool

Get if the text scroll style is changed.

Kind: instance method of `M5TextSCroll`

### ts.drawTextScroll() => void

Display text scroll.

Kind: instance method of `M5TextSCroll`

### ts.getScrollCount() => uint8_t

Get scrolling count.

Kind: instance method of `M5TextScroll`
