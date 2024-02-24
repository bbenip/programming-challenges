defmodule GuessingGame do
  def compare(secret_number, guess \\ nil)

  def compare(_secret_number, guess)  when not is_integer(guess) do
    "Make a guess"
  end

  def compare(secret_number, guess) when guess === secret_number do
    "Correct"
  end

  def compare(secret_number, guess) when abs(guess - secret_number) === 1 do
    "So close"
  end

  def compare(secret_number, guess) when guess > secret_number do
    "Too high"
  end

  def compare(secret_number, guess) when guess < secret_number do
    "Too low"
  end
end
