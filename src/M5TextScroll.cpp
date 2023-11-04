#include "M5TextScroll.h"

M5TextScroll::M5TextScroll() {
    canvas = new M5Canvas(&M5.Lcd);
    _x = 0;
    _y = 0;
    _scroll_pixel = 1;
    _bg_color = canvas->color888(0, 0, 0);
    _text_color = canvas->color888(255, 255, 255);
    _text_font = &fonts::Font4;
    _text_pos = 0;
    scroll_count = 0;
}

void M5TextScroll::setCusor(int32_t x, int32_t y, uint8_t scroll_pixel) {
    _x = x;
    _y = y;
    _scroll_pixel = scroll_pixel;
}

void M5TextScroll::setTextFont(const lgfx::IFont* font) { _text_font = font; }

void M5TextScroll::setBgColor(uint32_t color) { _bg_color = color; }

void M5TextScroll::setTextColor(uint32_t color) { _text_color = color; }

void M5TextScroll::setText(const char* text) {
    scroll_count = 0;
    canvas->setTextWrap(false);
    int32_t sprite_w = M5.Display.width() + canvas->textWidth(text);
    int32_t sprite_h = canvas->fontHeight(_text_font);
    canvas->createSprite(sprite_w, sprite_h);
    canvas->clear();
    strncpy(_text, text, 255);
    _text_len = sizeof(_text) / sizeof(_text[0]);
    _text_pos = 0;
    cursor_x = M5.Display.width();
}

void M5TextScroll::showTextScroll() {
    canvas->setTextColor(_text_color, _bg_color);
    canvas->setFont(_text_font);
    cursor_x = canvas->getCursorX() - 1;
    if (cursor_x <= 0) {
        _text_pos = 0;
        cursor_x = M5.Display.width();
        scroll_count++;
    }

    canvas->setCursor(cursor_x, 0);
    canvas->scroll(-_scroll_pixel, 0);
    while (_text_pos < _text_len && cursor_x <= M5.Display.width()) {
        canvas->print(_text[_text_pos++]);
        cursor_x = canvas->getCursorX();
    }

    canvas->pushSprite(&M5.Display, _x, _y);
}

uint8_t M5TextScroll::getScrollCount() { return scroll_count; }