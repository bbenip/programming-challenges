/**
 * @param {Function[]} functions
 * @return {Function}
 */

const compose = (functions) => (
  functions.reduce(
    (accumulator, currentFunction) => (
      (num) => accumulator(currentFunction(num))
    ),
    (num) => num
  )
);

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
