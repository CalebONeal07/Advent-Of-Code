const input = Bun.file("input/december2");
const text: string[] = (await input.text()).split("\r\n");

var sum = 0;
var ribbon = 0;

for (const i in text) {
  const line = text[i];
  if (line != null && line != "") {
    const dimensions: number[] = line.split("x").map((x) => parseInt(x));

    if (
      dimensions[0] == null ||
      dimensions[1] == null ||
      dimensions[2] == null
    ) {
      console.log("Line skipped: " + line);
      continue;
    }

    const l: number = dimensions[0];
    const w: number = dimensions[1];
    const h: number = dimensions[2];

    sum += 2 * l * w + 2 * w * h + 2 * h * l;
    const min = [l * w, w * h, h * l].sort((a, b) => a - b)[0];
    if (min != null) {
      sum += min;
    }

    ribbon += l * w * h;
    const per = [l + w, w + h, h + l].sort((a, b) => a - b)[0];
    if (per != null) {
      ribbon += 2 * per;
    }
  }
}

console.log(sum);
console.log(ribbon);
