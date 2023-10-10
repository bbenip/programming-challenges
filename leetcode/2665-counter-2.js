/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
const createCounter = (init) => {
  let addend = 0;

  return {
    increment: () => {
      addend += 1;
      return init + addend;
    },
    decrement: () => {
      addend -= 1;
      return init + addend;
    },
    reset: () => {
      addend = 0;
      return init;
    },
  }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
