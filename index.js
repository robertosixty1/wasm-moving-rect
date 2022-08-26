async function start()
{
    const game = await WebAssembly.instantiateStreaming(fetch('main.wasm'), {});
    const memoryView = new Uint8Array(game.instance.exports.memory.buffer);

    const displayAddr = game.instance.exports.get_display();
    const displayWidth = game.instance.exports.get_display_width();
    const displayHeight = game.instance.exports.get_display_height();
    const displaySize = displayWidth * displayHeight;
    const gameCanvas = document.getElementById('app');
    const ctx = gameCanvas.getContext('2d');

    function step(timestamp) {
        game.instance.exports.update();

        const frame = new ImageData(
            new Uint8ClampedArray(
                memoryView.subarray(
                    displayAddr,
                    displayAddr + 4 * displaySize)),
            displayWidth, displayHeight);
        ctx.putImageData(frame, 0, 0);

        window.requestAnimationFrame(step);
    }
    window.requestAnimationFrame(step);
}

start().catch((e) => console.log(e));
