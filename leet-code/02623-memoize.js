/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  const cachedResults = {};

  return function(...args) {
    const key = args.join('-');

    if (cachedResults.hasOwnProperty(key)) {
      return cachedResults[key];
    }

    const result = fn(...args);

    cachedResults[key] = result;

    return result;
  }
}


/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
