struct pidfth;

struct pidfh * pidfile_open(const char *_path, mode_t _mode, pid_t *_pidptr);
int	pidfile_remove(struct pidfh *_pfh);
int	pidfile_write(struct pidfh *_pfh);
