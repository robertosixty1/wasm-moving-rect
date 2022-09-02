typedef signed int int32_t;
typedef int32_t Pixel;

Pixel rgba(int32_t r, int32_t g, int32_t b, int32_t a)
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

int32_t get_display_width(void)
{
    return WIDTH;
}

int32_t get_display_height(void)
{
    return HEIGHT;
}

int32_t max(int32_t a, int32_t b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int32_t min(int32_t a, int32_t b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int32_t clamp(int32_t x, int32_t low, int32_t high)
{
    return min(max(low, x), high);
}

void fill_rect(int32_t x0, int32_t y0, int32_t w, int32_t h, Pixel pixel)
{
    int32_t
 x1 = clamp(x0, 0, (WIDTH - 1));
    int32_t
 x2 = clamp(x0 + w - 1, 0, (WIDTH - 1));
    int32_t
 y1 = clamp(y0, 0, (HEIGHT - 1));
    int32_t
 y2 = clamp(y0 + h - 1, 0, (HEIGHT - 1));

    for (int32_t
 y = y1; y <= y2; ++y) {
        for (int32_t
     x = x1; x <= x2; ++x) {
            display[y*WIDTH+x] = pixel;
        }
    }
}

int32_t x = 0;
int32_t y = 0;
#define DEFAULT_VELOCITY 2
int32_t vel_x = DEFAULT_VELOCITY;
int32_t vel_y = DEFAULT_VELOCITY;

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
