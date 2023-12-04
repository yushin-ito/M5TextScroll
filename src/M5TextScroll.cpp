#include "M5TextScroll.h"

static TaskHandle_t drawTaskHandle;

Context::Context(M5TextScroll* ts) {
    _ts = ts;
}

M5TextScroll* Context::getTextScroll() {
    return _ts;
}

static void drawLoop(void* args) {
    Context* ctx = reinterpret_cast<Context*>(args);
    M5TextScroll* ts = ctx->getTextScroll();

    while (ts->isDrawing() || ts->isChanged()) {
        if (ts->isDrawing()) {
            ts->drawTextScroll();
        }
        if (ts->isChanged()) {
            M5.Display.clear();
            ts->setChanged(false);
        }
        vTaskDelay(1);
    }
    vTaskDelete(NULL);
}

M5TextScroll::M5TextScroll() {
    canvas = new M5Canvas(&M5.Lcd);
    _drawing = false;
    _changed = false;
    _x = 0;
    _y = 0;
    _speed = 2;
    _font = &fonts::Font4;
    _text_pos = 0;
    scroll_count = 0;
    _bg_color = canvas->color888(0, 0, 0);
    _text_color = canvas->color888(255, 255, 255);
}

void M5TextScroll::setPosition(int32_t x, int32_t y) {
    _x = x;
    _y = y;
    _changed = true;
}

void M5TextScroll::setSpeed(uint8_t speed) {
    _speed = speed;
    _changed = true;
}

void M5TextScroll::setBgColor(uint32_t color) {
    _bg_color = color;
    _changed = true;
}

void M5TextScroll::setTextColor(uint32_t color) {
    _text_color = color;
    _changed = true;
}

void M5TextScroll::setFont(const lgfx::IFont* font) {
    int32_t _font_height = canvas->fontHeight(_font);
    if (MAX_FONT_HEIGHT < _font_height) return;

    _font = font;
    _changed = true;
}

void M5TextScroll::setText(const char* text) {
    scroll_count = 0;

    strncpy(_text, text, 255);
    _text_len = sizeof(_text) / sizeof(_text[0]);

    canvas->clear();

    _text_pos = 0;
    cursor_x = M5.Display.width();

    _changed = true;
}


void M5TextScroll::init(int32_t x, int32_t y) {
    _x = x;
    _y = y;

    int32_t _sprite_width = M5.Display.width() + MAX_FONT_HEIGHT;
    int32_t _sprite_height = MAX_FONT_HEIGHT;

    canvas->createSprite(_sprite_width, _sprite_height);

    start();
}

void M5TextScroll::start() {
    if (_drawing) return;
    _drawing = true;

    Context* ctx = new Context(this);

    xTaskCreateUniversal(drawLoop,
        "drawLoop",
        2048,
        ctx,
        3,
        &drawTaskHandle,
        APP_CPU_NUM);
}

void M5TextScroll::stop() {
    _drawing = false;
}

bool M5TextScroll::isDrawing() {
    return _drawing;
}

bool M5TextScroll::isChanged() {
    return _changed;
}

void M5TextScroll::setChanged(bool changed) {
    _changed = changed;
}

void M5TextScroll::drawTextScroll() {
    canvas->setTextWrap(false);
    canvas->setFont(_font);
    canvas->setTextColor(_text_color, _bg_color);

    cursor_x = canvas->getCursorX() - _speed;
    if (cursor_x <= 0) {
        _text_pos = 0;
        cursor_x = M5.Display.width();
        scroll_count++;
    }

    canvas->setCursor(cursor_x, 0);
    canvas->scroll(-_speed, 0);
    while (_text_pos < _text_len && cursor_x <= M5.Display.width()) {
        canvas->print(_text[_text_pos++]);
        cursor_x = canvas->getCursorX();
    }
    M5.Display.waitDisplay();

    canvas->pushSprite(&M5.Display, _x, _y);
}

uint8_t M5TextScroll::getScrollCount() {
    return scroll_count;
}