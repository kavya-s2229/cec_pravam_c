function renderTasks(tasks) {
  let list = document.getElementById("task-list");
  list.innerHTML = "";
  tasks.forEach((task) => {
    let statusClass = task.completed
      ? "task-completed"
      : isOverdue(task.date)
        ? "task-overdue"
        : "task-pending";

    list.innerHTML += `
      <div class="task-box ${statusClass}">
        <span>${task.text}</span>
        <div>
          <button class="edit" onclick="editTask('${task.id}')">Edit</button>
          <button class="delete" onclick="deleteTask('${task.id}')">Delete</button>
          <button class="complete" onclick="completeTask('${task.id}')">Complete</button>
        </div>
      </div>
    `;
  });
}

function isOverdue(date) {
  let today = new Date().toISOString().split("T")[0];
  return date < today;
}

function addTask(text, date) {
  db.collection("tasks").add({
    text,
    date,
    completed: false,
    userId: firebase.auth().currentUser.uid,
  });
}

function editTask(id) {
  let newText = prompt("Edit task:");
  if (newText) {
    db.collection("tasks").doc(id).update({ text: newText });
  }
}

function deleteTask(id) {
  db.collection("tasks").doc(id).delete();
}

function completeTask(id) {
  db.collection("tasks").doc(id).update({ completed: true });
}
