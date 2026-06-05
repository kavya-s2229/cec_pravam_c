document.addEventListener("DOMContentLoaded", function () {
  let calendarEl = document.getElementById("calendar");
  let calendar = new FullCalendar.Calendar(calendarEl, {
    initialView: "dayGridMonth",
    events: [], // will be populated from DB
  });
  calendar.render();
});

// Auto-rollover incomplete tasks
function rolloverTasks() {
  let today = new Date().toISOString().split("T")[0];
  let yesterday = new Date(Date.now() - 86400000).toISOString().split("T")[0];

  db.collection("tasks")
    .where("date", "==", yesterday)
    .get()
    .then((snapshot) => {
      snapshot.forEach((doc) => {
        if (!doc.data().completed) {
          db.collection("tasks").add({
            text: doc.data().text,
            completed: false,
            date: today,
            userId: firebase.auth().currentUser.uid,
          });
        }
      });
    });
}
