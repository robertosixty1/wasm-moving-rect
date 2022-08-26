typedef unsigned int uint32_t;
typedef uint32_t Pixel;

Pixel rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
    return (a << (3 * 8)) |
           (b << (2 * 8)) |
           (g << (1 * 8)) |
           (r << (0 * 8));
}

#define WIDTH  640
#define HEIGHT 420
static Pixel display[WIDTH*HEIGHT] = {0};

Pixel* get_display(void)
{
    return display;
}

uint32_t get_display_width(void)
{
    return WIDTH;
}

uint32_t get_display_height(void)
{
    return HEIGHT;
}

uint32_t max(uint32_t a, uint32_t b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

uint32_t min(uint32_t a, uint32_t b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

uint32_t clamp(uint32_t x, uint32_t low, uint32_t high)
{
    return min(max(low, x), high);
}

void fill_rect(uint32_t x0, uint32_t y0, uint32_t w, uint32_t h, Pixel pixel)
{
    uint32_t x1 = clamp(x0, 0, (WIDTH - 1));
    uint32_t x2 = clamp(x0 + w - 1, 0, (WIDTH - 1));
    uint32_t y1 = clamp(y0, 0, (HEIGHT - 1));
    uint32_t y2 = clamp(y0 + h - 1, 0, (HEIGHT - 1));

    for (uint32_t y = y1; y <= y2; ++y) {
        for (uint32_t x = x1; x <= x2; ++x) {
            display[y*WIDTH+x] = pixel;
        }
    }
}

uint32_t x = 0;
uint32_t y = 0;
#define DEFAULT_VELOCITY 2
uint32_t vel_x = DEFAULT_VELOCITY;
uint32_t vel_y = DEFAULT_VELOCITY;

#define RECT_WIDTH  100
#define RECT_HEIGHT 100
void update()
{
    for (int i = 0; i < WIDTH*HEIGHT; ++i) display[i] = rgba(18, 18, 18, 255);
    fill_rect(x, y, 100, 100, rgba(255, 221, 51, 255));

    if ((x + RECT_WIDTH)  > WIDTH  || x < 0) vel_x = -vel_x;
    if ((y + RECT_HEIGHT) > HEIGHT || y < 0) vel_y = -vel_y;

    x += vel_x;
    y += vel_y;
}
