const fs = require('fs');
const path = require('path');

const root = process.cwd();
const README = path.join(root, 'README.md');

// Match folders like 0001-two-sum, 2126-destroying-asteroids
const problemFolders = fs.readdirSync(root, { withFileTypes: true })
  .filter(d => d.isDirectory() && /^\d{4}-/.test(d.name));

const count = problemFolders.length;

let readme = fs.readFileSync(README, 'utf8');

const startTag = '<!---Question Count Start--->';
const endTag = '<!---Question Count End--->';
const block = `${startTag}\n### ✅ Total Questions Solved: ${count}\n${endTag}`;

if (readme.includes(startTag) && readme.includes(endTag)) {
  readme = readme.replace(new RegExp(`${startTag}[\\s\\S]*?${endTag}`), block);
} else {
  const lines = readme.split('\n');
  lines.splice(1, 0, '', block);
  readme = lines.join('\n');
}

fs.writeFileSync(README, readme);
console.log(`Updated count: ${count}`);
