/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
const filter = (arr, fn) => {
  const output = [];

  arr.forEach((element, index) => {
    if (fn(element, index)) {
      output.push(element);
    }
  });

  return output;
};
