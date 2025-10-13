const input = Bun.file("input/december1");

const text = await input.text();

var output = 0;
var count = 0;

for (const char of text) {
  if (char == "(") {
    output += 1;
  } else if (char == ")") {
    output -= 1;
  }
  count += 1;
  if (output == -1) {
    break;
  }
}

console.log(output);
console.log(count);
