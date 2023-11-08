/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
const reduce = (nums, fn, init) => {
  let value = init;

  nums.forEach((num) => {
    value = fn(value, num);
  });

  return value;
};
