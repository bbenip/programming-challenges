defmodule TakeANumberDeluxe do
  use GenServer

  # Client API

  @spec start_link(keyword()) :: {:ok, pid()} | {:error, atom()}
  def start_link(init_arg) do
    GenServer.start_link(__MODULE__, init_arg)
  end

  @spec report_state(pid()) :: TakeANumberDeluxe.State.t()
  def report_state(machine) do
    GenServer.call(machine, :report_state)
  end

  @spec queue_new_number(pid()) :: {:ok, integer()} | {:error, atom()}
  def queue_new_number(machine) do
    GenServer.call(machine, :queue_new_number)
  end

  @spec serve_next_queued_number(pid(), integer() | nil) :: {:ok, integer()} | {:error, atom()}
  def serve_next_queued_number(machine, priority_number \\ nil) do
    GenServer.call(machine, {:serve_next_queued_number, priority_number})
  end

  @spec reset_state(pid()) :: :ok
  def reset_state(machine) do
    GenServer.call(machine, :reset_state)
  end

  # Server callbacks

  @impl GenServer
  def init(state) do
    min_number = Keyword.get(state, :min_number)
    max_number = Keyword.get(state, :max_number)
    timeout = Keyword.get(state, :auto_shutdown_timeout, :infinity)

    result = TakeANumberDeluxe.State.new(min_number, max_number, timeout)

    case result do
      {:ok, state} -> {:ok, state, state.auto_shutdown_timeout}
      {:error, error} -> {:stop, error}
    end
  end

  @impl GenServer
  def handle_call(:report_state, _from, state) do
    {:reply, state, state, state.auto_shutdown_timeout}
  end

  @impl GenServer
  def handle_call(:queue_new_number, _from, state) do
    result = TakeANumberDeluxe.State.queue_new_number(state)

    case result do
      {:ok, new_number, new_state} ->
        {:reply, {:ok, new_number}, new_state, state.auto_shutdown_timeout}

      {:error, _} ->
        {:reply, result, state, state.auto_shutdown_timeout}
    end
  end

  @impl GenServer
  def handle_call({:serve_next_queued_number, priority_number}, _from, state) do
    result = TakeANumberDeluxe.State.serve_next_queued_number(state, priority_number)

    case result do
      {:ok, next_number, new_state} ->
        {:reply, {:ok, next_number}, new_state, state.auto_shutdown_timeout}

      {:error, _} ->
        {:reply, result, state, state.auto_shutdown_timeout}
    end
  end

  @impl GenServer
  def handle_call(:reset_state, _from, state) do
    result = TakeANumberDeluxe.State.new(
               state.min_number,
               state.max_number,
               state.auto_shutdown_timeout
             )

    case result do
      {:ok, new_state} -> {:reply, :ok, new_state, new_state.auto_shutdown_timeout}
      {:error, _} -> {:reply, result, state, state.auto_shutdown_timeout}
    end
  end

  @impl GenServer
  def handle_info(:timeout, state) do
    {:stop, :normal, state}
  end

  @impl GenServer
  def handle_info(_, state) do
    {:noreply, state, state.auto_shutdown_timeout}
  end
end
