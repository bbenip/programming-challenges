/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
const timeLimit = (fn, t) => {
  return async function(...args) {
    return Promise.race([
      new Promise((_resolve, reject) => {
        setTimeout(() => reject('Time Limit Exceeded'), t);
      }),
      fn(...args),
    ]);
  };
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
