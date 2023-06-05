// create a new worker
const worker = new Worker("./generate.js");

// when user clicks "Generate primes", send message to worker
// the message cmd is "generate"; and the message also contains "quota",
// which is the num of primes to generate.
document.querySelector("#generate").addEventListener("click", () => {
  const quota = document.querySelector("#quota").ariaValueMax;
  worker.postMessage({
    command: "generate",
    quota,
  });
});

// when the worker sends a message back to the main thread
// update the output box with a message for the user,
// including the number of primes that were generated,
// taken from the message data
worker.addEventListener("message", (message) => {
  document.querySelector("#output").textContent = `Finished generating ${message.data} primes!`;
});

document.querySelector("#reload").addEventListener("click", () => {
  document.querySelector("#user-input").value =
    'Try typing in here immediately after pressing "Generate primes"';
  document.location.reloat();
});