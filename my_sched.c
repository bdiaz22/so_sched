const struct sched_class myfifo_sched_class = {
    .next            = &fair_sched_class,
    .enqueue_task        = enqueue_task_fifo,
    .dequeue_task        = dequeue_task_fifo,
    .yield_task        = yield_task_fifo,
    .yield_to_task        = yield_to_task_fifo,

    .check_preempt_curr    = check_preempt_curr_fifo,

    .pick_next_task        = pick_next_task_fifo,
    .put_prev_task        = put_prev_task_fifo,

#ifdef CONFIG_SMP
    .select_task_rq        = select_task_rq_fifo,
    .migrate_task_rq    = migrate_task_rq_fifo,

    .rq_online        = rq_online_fifo,
    .rq_offline        = rq_offline_fifo,

    .task_dead        = task_dead_fifo,
    .set_cpus_allowed    = set_cpus_allowed_common,
#endif

    .set_curr_task          = set_curr_task_fifo,
    .task_tick        = task_tick_fifo,
    .task_fork        = task_fork_fifo,

    .prio_changed        = prio_changed_fifo,
    .switched_from        = switched_from_fifo,
    .switched_to        = switched_to_fifo,

    .get_rr_interval    = get_rr_interval_fifo,

    .update_curr        = update_curr_fifo,

#ifdef CONFIG_fifo_GROUP_SCHED
    .task_change_group    = task_change_group_fifo,
#endif

static struct task_struct *pick_next_task_fifo(struct rq *rq, struct task_struct *prev, struct rq_flags *rf)
{
    struct newfifo *fifo;
    struct task_struct *p;


    fifo = rq->fifo_rq->fifo;
    kfifout(fifo, sizeof(struct task_struct*));

    return p;
}
