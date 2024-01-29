const TimeLimitedCache = function() {
  this.cache = {};
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
  const cacheEntry = this.cache[key];
  const isAlreadyInCache = cacheEntry !== undefined;

  if (isAlreadyInCache) {
    const { expiryTimeout: originalExpiryTimeout } = cacheEntry;
    clearTimeout(originalExpiryTimeout);
  } else {
    this.cache[key] = {};
  }

  const expiryTimeout = setTimeout(() => delete this.cache[key], duration);

  this.cache[key].value = value;
  this.cache[key].expiryTimeout = expiryTimeout;

  return isAlreadyInCache;
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
  return this.cache[key]?.value ?? -1;
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
  return Object.entries(this.cache).length;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
