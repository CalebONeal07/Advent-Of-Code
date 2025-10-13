const input = Bun.file("input1");

const text = await input.text();

var output = 0;

for (const char of text) {
  if (char == "(") {
    output += 1;
  } else if (char == ")") {
    output -= 1;
  }
}

console.log(output);
