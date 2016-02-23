package no.sonat.collector.influx;

import com.codahale.metrics.health.HealthCheck;
import io.dropwizard.ConfiguredBundle;
import io.dropwizard.setup.Bootstrap;
import io.dropwizard.setup.Environment;
import org.influxdb.InfluxDB;
import org.influxdb.InfluxDBFactory;
import org.influxdb.dto.Pong;

/**
 * @author zapodot
 */
public class InfluxBundle implements ConfiguredBundle<HasInfluxConfiguration> {


    private InfluxDB influxDB;

    public InfluxDB getInfluxDB() {
        return influxDB;
    }

    @Override
    public void run(final HasInfluxConfiguration configuration, final Environment environment) throws Exception {
        final InfluxConfiguration influxConfiguration = configuration.getInfluxConfiguration();
        influxDB = InfluxDBFactory.connect(influxConfiguration.url, influxConfiguration.userName, influxConfiguration.password);
        environment.healthChecks().register("influxdb-" + influxConfiguration.database, new HealthCheck() {
            @Override
            protected Result check() throws Exception {
                try {
                    final Pong pong = influxDB.ping();
                    if (pong != null && pong.getVersion() != null) {
                        return Result.healthy(String.format("v: %s, response: %s",
                                pong.getVersion(),
                                pong.getResponseTime()));
                    } else {
                        return Result.unhealthy("failed to ping influxdb");
                    }
                } catch (Throwable t) {
                    return Result.unhealthy(t);
                }
            }
        });

    }

    @Override
    public void initialize(final Bootstrap<?> bootstrap) {

    }
}
