defmodule Lasagna do
  def expected_minutes_in_oven, do: 40

  def remaining_minutes_in_oven(minutes_cooked) do
    expected_minutes_in_oven() - minutes_cooked
  end

  def preparation_time_in_minutes(layers) do
    layers * 2
  end

  def total_time_in_minutes(layers, time_in_oven) do
    preparation_time_in_minutes(layers) + time_in_oven
  end

  def alarm, do: "Ding!"
end
